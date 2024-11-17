#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>

class Log {
public:
	Log(): thr(&Log::cicleWriteMessage, this) {
		file.open("tes.txt");
	}

	void putMessage(const std::string& mes) {
		messages.push_back(mes);
		cv.notify_one();
	}


	void cicleWriteMessage() {

		while (true) {
			if (!messages.empty()) {
				auto m = messages.back();
				messages.pop_back();
				writeMessage(m);
			}
			
			if (messages.empty())
			{
				std::unique_lock l(m);
				cv.wait(l, [this]() { return !messages.empty(); });
			}

			std::cout << "do nothing ";
		
		}

	}

private:

	

	void writeMessage(const std::string& message) {
		std::cout << "							from log class: "
			<< "thread id =" << std::this_thread::get_id() << " "
			<< message << std::endl;
		file << "									from log class: " << message << std::endl;
	}

	std::fstream file;
	std::vector<std::string> messages;
	std::thread thr;

	std::condition_variable cv;
	std::mutex m;

};