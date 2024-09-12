#include <iostream>
#include <chrono>
#include <ctime>
#include <mutex>

class AuditClient
{
private:
	static AuditClient* instance;
	static std::mutex mtx;

	/*
	 * AuditClient() {}
	 * AuditClient(const AuditClient&) = delete;
	 * AuditClient& operator=(const AuditClient&) = delete;
	 */
public:
	static void AuditLog(const std::string id,
		 	     const std::string component,
			     const std::chrono::system_clock::time_point& tp,
			     const std::string audit_entry);

	//static AuditClient* getInstance();
};
