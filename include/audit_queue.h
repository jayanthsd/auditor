#include <iostream>
#include <queue>
#include <mutex>
#include <semaphore.h>


class AuditQueue
{
	std::queue<std::string> audit_entries;
	std::mutex mtx;
	sem_t sem_queue;
	

	static AuditQueue* instance;
	static std::mutex instance_mtx;


	AuditQueue() {}
	AuditQueue(const AuditQueue&) = delete;
	AuditQueue& operator=(const AuditQueue&) = delete;


public:
	static AuditQueue* getInstance();

	void push(const std::string& string);
	std::string pop();
	void clear();

};
