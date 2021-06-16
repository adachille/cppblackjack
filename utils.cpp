#include <chrono> // for sleep
#include <thread> // for sleeeping

void sleep(long ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
