#include <iostream>
#include "audit_client.h"
#include "audit_queue.h"
#include "json.hpp"


void AuditClient::AuditLog(const std::string id,
		 	   const std::string component,
			   const std::chrono::system_clock::time_point& tp,
			   const std::string audit_entry)
{
	AuditQueue* aq = AuditQueue::getInstance();

	json entry = json::parse(audit_entry);
	json final_entry = {
		{"id", id},
		{"component", component},
		{"time", time}
	};

	for (auto& el : entry.items())
       	{
        	final_entry[el.key()] = el.value();
    	}

	aq->push(final_entry.dump());
}
