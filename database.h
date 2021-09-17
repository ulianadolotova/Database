#pragma once

#include "date.h"
#include "event_storage.h"





//--------------------------------------------------------------------------------------------

struct Entry {

	const Date& date;
	const std::string& event;	
};


std::ostream& operator << (std::ostream& stream, const Entry& entry);

//--------------------------------------------------------------------------------------------



class Database {

public:

	void Add(const Date& date, const std::string& event);

	void Print(std::ostream& stream) const;



	template <typename UnaryPredicate>
	int RemoveIf(UnaryPredicate p) {

    	int count = 0;

    	for (const auto& [i_date, i_storage] : base) {

    		const Date temp = i_date;

        	count += base[i_date].RemoveIf([=](const std::string& event) {

        		return p(temp, event);
      		});
    	}

    	for (auto it = base.begin(); it != base.end(); ) {

      		if (it->second.GetAccessToTimeLine().empty()) {

        		base.erase(it++);

      		} else {

        		++it;
      		}
    	}

    	return count;
	}


	template <typename UnaryPredicate>
  	std::vector<Entry> FindIf(UnaryPredicate p) const {

    	std::vector<Entry> result;

    	for (const auto& [i_date, i_storage] : base) {

      		for (const auto& event : i_storage.GetAccessToTimeLine()) {

        		if (p(i_date, event)) {

          			result.push_back(Entry{i_date, event});
        		}
      		}
    	}

    	return result;
  }


	Entry Last(const Date& date) const;

  	//bool DeleteEvent(const Date& date, const std::string& event);


  	//int DeleteDate(const Date& date);


  	//std::set<std::string> Find(const Date& date) const;


private:

	std::map<Date, EventStorage> base;	

};


//--------------------------------------------------------------------------------------------------------
