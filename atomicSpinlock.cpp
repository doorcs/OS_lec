#include <iostream>
#include <atomic>
#include <thread>

std::atomic_flag lock = ATOMIC_FLAG_INIT;

int data; // 전역 변수는 모든 쓰레드 간에 공유됨!

void func(int id) {
  for (int i = 0; i < 5; i++) {
    while (lock.test_and_set(std::memory_order_acquire)) {
      while (lock.test(std::memory_order_relaxed)) ; // spinning, busy-waiting
    }
    data++;
    std::cout << "Now thread " << id << " running! data: " << data << '\n';
    lock.clear(std::memory_order_release);
    std::this_thread::yield();
  }
}

int main() {
  std::thread t1(func, 1);
  std::thread t2(func, 2);
  std::thread t3(func, 3);

  t1.join(), t2.join(), t3.join();

  std::cout << "fin! data: " << data << '\n';
}
