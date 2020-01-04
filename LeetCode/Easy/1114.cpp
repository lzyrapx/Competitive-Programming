/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-22 22:59:23
 */
class Foo {
private:
        std::mutex mtx{};
        std::condition_variable cv{};
        std::atomic<bool> is_called1{false};
        std::atomic<bool> is_called2{false};
public:
    Foo() {
        
    }
    
    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        is_called1 = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lck(mtx);
        while(!is_called1) cv.wait(lck);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        is_called2 = true;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lck(mtx);
        while(!is_called2) cv.wait(lck);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};