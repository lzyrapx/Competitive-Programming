###
 # @Author: zhaoyang.liang
 # @Github: https://github.com/LzyRapx
 # @Date: 2020-02-17 00:53:09
 ###
# Read from the file words.txt and output the word frequency list to stdout.
tr ' ' '\12' < words.txt  | sed '/^$/d'| sort |uniq -c | sort -nr | awk '{print $2, $1}'
