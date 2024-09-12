#include <iostream>
#include "audit_client.h"
#include <chrono>
#include "json.hpp"

using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
using json = nlohmann::json;

int main()
{
	TimePoint now = std::chrono::high_resolution_clock::now();
	json j = {
			{"type", "Api"},
		       	{"name", "createVirtualVolume"},
		       	{"containerid", "c1"},
		       	{"task_id", "TASK_1"}
    	};

	std::cout << "************** Request ******************" << std::endl;
	std::cout << j.dump(4) << std::endl;
	std::cout << "************** Complete ******************" << std::endl;

	AuditClient::AuditLog("1", "VASA", now, j.dump());
	sleep(1);
	AuditClient::AuditLog("2", "VASA", now, j.dump());
	sleep(1);
	AuditClient::AuditLog("3", "VASA", now, j.dump());
	sleep(1);
	AuditClient::AuditLog("4", "VASA", now, j.dump());

	return 0;
}
