#pragma once

#include "date.h"

#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <functional>

class EventStorage {

public:

	void Add(const std::string& event);

	const std::vector<std::string>& GetAccessToTimeLine() const;

	template <typename UnaryPredicate>
	int RemoveIf(UnaryPredicate p) {

		int count = 0;

		auto it = std::find_if(ordered.begin(), ordered.end(), p);

		while (it != ordered.end()) {

			++count;

			it = ordered.erase(it);
			it = std::find_if(it, ordered.end(), p);
		}

		auto it_end = std::stable_partition(time_line.begin(),
		                                    time_line.end(), p);

		time_line.erase(time_line.begin(), it_end);

		return count;
	}


private:

	std::set<std::string> ordered;

	std::vector<std::string> time_line;
};