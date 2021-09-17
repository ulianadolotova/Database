#include "event_storage.h"


void EventStorage::Add(const std::string& event) {

	if (ordered.count(event) == 0) {

		ordered.insert(event);
		time_line.push_back(event);

	}
}


const std::vector<std::string>& EventStorage::GetAccessToTimeLine() const {

	return time_line;
}
