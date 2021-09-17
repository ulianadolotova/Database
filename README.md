# Database


- <b> Add </b> <i> date event </i> — add a pair (<i> date, event </i>) to the database;

- <b> Print </b> — output all records of the database;

- <b> Find </b> <i> condition </i> — output all records contained in the database that satisfy the <i> condition; </i>

- <b> Del </b> <i> condition </i> — delete all records from the database that satisfy the <i> condition; </i>

- <b> Last </b> <i> date </i> — output a record with the last event that occurred no later than this <i> date. </i>



The conditions in the <b> Find </b> and <b> Del </b> commands put certain restrictions on dates and events, for example:

- Find date < 2017-11-06 — find all events that happened earlier than November 6, 2017;

- Del event != "holiday" — delete all events from the database except "holiday";

- Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event" — find all the "sport event" events that happened in the first half of 2017;

- Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event") — delete all "holiday" and "sport event" events that occurred before 2017 from the database.

In both types of commands, the conditions can be empty: <b> all </b> events fall under this condition.
