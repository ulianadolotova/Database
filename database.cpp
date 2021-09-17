#include "database.h"

void Database::Add(const Date& date, const std::string& event) {

	base[date].Add(event);

}


void Database::Print(std::ostream& stream) const {

    for (const auto& [i_date, i_storage] : base) {

        for (const auto& event : i_storage.GetAccessToTimeLine()) {

            stream << i_date << " " << event << std::endl;
        }
    }
}


Entry Database::Last(const Date& date) const {

    auto it = base.upper_bound(date);

    if (it == base.begin()) {

        throw std::invalid_argument("No entries");
    }

    --it;

    return {it->first, it->second.GetAccessToTimeLine().back()};
}


/*bool Database::DeleteEvent(const Date& date, const std::string& event) {

  	if (base.count(date) > 0 && base[date].count(event) > 0) {

  		  base[date].erase(event);

  		  return true;
  	}

  	return false;
}


int Database::DeleteDate(const Date& date) {

  	int count_events = 0;

  	if (base.count(date) <= 0) {

  		return count_events;
  	}

  	count_events = base[date].size();

  	base.erase(date);

  	return count_events;
 }


 std::set<std::string> Database::Find(const Date& date) const {

  	std::set<std::string> result;

  	if (base.count(date) > 0) {

  		result = base.at(date);
  	}

  	return result;
 }*/


/*std::string ParseEvent(std::istream& is) {
    
    std::string temp;

    is >> std::ws;

    std::getline(is, temp);

    return temp;
}*/


std::ostream& operator << (std::ostream& stream, const Entry& entry) {

    stream << entry.date << " " << entry.event;

    return stream;
}



/*int main() {

	Database db;

	for (std::string line; std::getline(std::cin, line); ) {

    std::istringstream is(line);

    std::string command;
    is >> command;
    if (command == "Add") {
      const auto date = ParseDate(is);
      const auto event = ParseEvent(is);
      db.Add(date, event);
      std::cout << "Here\n";
      db.Print();
    }

	}

	db.Print();
}*/



