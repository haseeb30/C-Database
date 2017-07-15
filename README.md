# C-Database
A simple database to store the records of a file in a linked list such that it will be 
faster to search for any record.
The file is read record by record, each record is hashed to a specific location. If 
more than one record is mapped to the same location, it is stored in a linked list 
pointed to by the location.
