#include <chrono>
#include <deque>
#include <format>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main() {
  std::mutex mx{};
  std::deque<std::string> messages{};
  std::atomic<bool> completed{false};

  auto senderCompleted = std::async([&mx, &messages, &completed] {
    for (std::size_t messageCount = 0; messageCount < 10; ++messageCount) {
      std::this_thread::sleep_for(1s);
      auto _ = std::unique_lock{mx};
      messages.push_back(std::format("Message no. {}", messageCount + 1));
    }
    completed = true;
  });

  auto receiverCompleted = std::async([&mx, &messages, &completed] {
    while (completed != true) {
      std::this_thread::sleep_for(200ms);
      {
        std::unique_lock _{mx};

        if (messages.empty()) {
          std::cout << std::format("No messages found\n");
        } else {
          std::string message = std::move(messages.front());
          messages.pop_front();
          std::cout << std::format("Message received: {}\n", message);
        }
      }
    }
  });

  senderCompleted.get();
  receiverCompleted.get();

  return 0;
}