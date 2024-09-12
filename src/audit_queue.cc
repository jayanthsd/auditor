#include "audit_queue.h"

#define AUDIT_QUEUE_SIZE 1000


AuditQueue* AuditQueue::instance = nullptr;
std::mutex AuditQueue::instance_mtx;

AuditQueue* AuditQueue::getInstance()
{
	std::lock_guard<std::mutex> lock(instance_mtx);
	if(instance == nullptr)
	{
		instance = new AuditQueue();
	}
	return instance;
}

void AuditQueue::push(const std::string& string)
{
	std::cout << "Invoked AuditQueue::push" << std::endl;
	sem_wait(&sem_queue);
	std::lock_guard<std::mutex> lock(mtx);

	audit_entries.push(string);
	std::cout << "Pushed audit entry successfully. QueueSize[" << audit_entries.size() << "]" << std::endl;

}

std::string AuditQueue::pop()
{
	std::cout << "Invoked AuditQueue::push" << std::endl;
	std::lock_guard<std::mutex> lock(mtx);
	std::string entry = audit_entries.front();
	audit_entries.pop();

	sem_post(&sem_queue);
	std::cout << "Popped audit entry successfully. QueueSize[" << audit_entries.size() << "]" << std::endl;
	return entry;
}

void AuditQueue::clear()
{
	std::cout << "Invoked AuditQueue::clear" << std::endl;
	std::lock_guard<std::mutex> lock(mtx);
	while(!audit_entries.empty())
	{
		audit_entries.pop();
		sem_post(&sem_queue);
	}
	std::cout << "Cleared AuditQueue. QueueSize[" << audit_entries.size() << "]" << std::endl;
}
