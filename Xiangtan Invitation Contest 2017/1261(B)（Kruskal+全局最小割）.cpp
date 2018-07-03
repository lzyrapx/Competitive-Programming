#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
pair<int, vector<int>> MinimunCut(vector<vector<int>> &weights) //全局最小割 
{
    int N = weights.size();
    vector<int> used(N), cut, best_cut;
    int best_weight = -1;
  
    for (int phase = N-1; phase >= 0; phase--) 
    {
        vector<int> w = weights[0];
        vector<int> added = used;
        int prev, last = 0;
        for (int i = 0; i < phase; i++) 
        {
            prev = last;
            last = -1;
            for (int j = 1; j < N; j++)
            {
                if (!added[j] && (last == -1 || w[j] > w[last])) last = j;
            }
            if (i == phase-1) 
            {
                for (int j = 0; j < N; j++) weights[prev][j] += weights[last][j];
                for (int j = 0; j < N; j++) weights[j][prev] = weights[prev][j];
                
                used[last] = true;
                cut.push_back(last);
                if (best_weight == -1 || w[last] < best_weight) 
                {
                    best_cut = cut;
                    best_weight = w[last];
                }
            }
            else 
            {
                for (int j = 0; j < N; j++)
                {
                    w[j] += weights[last][j];
                    added[last] = true;
                }
            }
        }
    }
    return make_pair(best_weight, best_cut);
}
int n,m,fa[500],mp[60][60] ;
struct Edge
{
        int u , v , w;
        friend bool operator < (const Edge & x , const Edge & y)
        {
                return x.w < y.w;
        }
        Edge( int u , int v , int w ) : u( u ) , v( v ) , w( w ){}
};

int find_fa( int u )
{
        return fa[u] != u ? fa[u] = find_fa( fa[u] ) : u;
}

void union_set( int u , int v )
{
        int p1 = find_fa( u ) , p2 = find_fa( v );
        if( p1 != p2 ) fa[p1] = p2;
}

vector < Edge > vi;
vector < pair < int , int > > ret;

int id[60] , tot;
vector < int > wr;

void DFS( int u )
{
    id[u] = ++ tot;
    wr.emplace_back( u );
    for(int i = 1 ; i <= n ; i++)
    {
    	if( mp[u][i] && !id[i] )
            DFS( i );
	}
        
}

int Kruskal()
{
    memset( id , 0 , sizeof( id ));
    int ret = 1 << 30;
    for(int i = 1 ; i <= n ; i++)
    {
    	if( !id[i] )
        {
            wr.clear();
            tot = 0;
            DFS( i );
            function < bool( int  , int ) > cmp = [](const int & x , const int & y)
            {
                return id[x] < id[y];
            };
            sort( wr.begin() , wr.end() , cmp );
            vector < vector < int > > Graph;
            for(auto it : wr)
            {
                vector < int > path;
                path.resize( wr.size() , 0 );
                for(int i = 1 ; i <= n ; i++)
                {
                	if( mp[it][i] )
                	{
                		 path[ id[i] - 1 ] = mp[it][i];
					}
                       
				}
                    
                Graph.emplace_back( path );
            }
            if( tot > 1 )
            {
            	ret = min( ret , MinimunCut( Graph ).first );
			}
                
         }
	}
        
    return ret;
}

int main()
{
    while(~scanf("%d%d" ,& n,&m ))
    {
        for(int i = 1 ; i <= n ; i++) fa[i] = i;
        ret.clear();
        vi.clear();
        for(int i = 1 ; i <= m ; i++)
        {
            int u , v , c;
            scanf( "%d%d%d" , & u , & v , & c );
            vi.emplace_back( Edge( u , v , c ) );
        }
        sort( vi.begin() , vi.end() );
        int ans = 1 << 30;
        for(int i = 0 , k = 0 ; k < n - 1 ; )
		{
            int j = i;
            while( j < vi.size() && vi[j].w == vi[i].w )
            {
            	j++;
			}
                    
            memset( mp , 0 , sizeof( mp ) );
            for(int v = i ; v < j ; ++ v)
			{
                if( find_fa( vi[v].u ) != find_fa( vi[v].v ) )
                {
                	 k++;
				}
                       
                ++ mp[vi[v].u][vi[v].v];
                ++ mp[vi[v].v][vi[v].u];
                union_set( vi[v].u , vi[v].v );
            }
            i = j;
            ans = min( ans , Kruskal( ));
        }
        printf("%d\n" , ans );
    }
    return 0;
}