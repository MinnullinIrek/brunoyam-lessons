CREATE TABLE "Classes" (
	"id"	INTEGER NOT NULL UNIQUE,
	"number"	INTEGER,
	"litera"	TEXT,
	PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE Persons (id INTEGER PRIMARY KEY, name TEXT, year TEXT, adres TEXT);
CREATE TABLE "Pupils" (
	"id"	INTEGER NOT NULL UNIQUE,
	"class_id"	INTEGER NOT NULL,
	"person_id"	INTEGER NOT NULL,
	PRIMARY KEY("id" AUTOINCREMENT),
	FOREIGN KEY("class_id") REFERENCES "",
	FOREIGN KEY("person_id") REFERENCES ""
)
CREATE TABLE "Subjects" (
	"id"	INTEGER NOT NULL UNIQUE,
	"name"	TEXT NOT NULL,
	PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE "Teachers" (
	"id"	INTEGER NOT NULL UNIQUE,
	"person_id"	INTEGER NOT NULL,
	"subject_id"	INTEGER NOT NULL,
	PRIMARY KEY("id" AUTOINCREMENT),
	FOREIGN KEY("person_id") REFERENCES "",
	FOREIGN KEY("subject_id") REFERENCES "Subjects"("id")
);

INSERT INTO Classes  (number, litera) VALUES (1, "A");
INSERT INTO Classes  (number, litera) VALUES (2, "A");
INSERT INTO Classes  (number, litera) VALUES (1, "B");
INSERT INTO Classes  (number, litera) VALUES (2, "B");

INSERT INTO Persons  (name, year, adres) VALUES ("Ivanov", "1999", "mosk1");
INSERT INTO Persons  (name, year, adres) VALUES ("Vas", "1978", "mosk2");
INSERT INTO Persons  (name, year, adres) VALUES ("VLad", "1999", "mosk3");
INSERT INTO Persons  (name, year, adres) VALUES ("Egor", "1999", "mosk4");
INSERT INTO Persons  (name, year, adres) VALUES ("Ildar", "1999", "mosk5");
INSERT INTO Persons  (name, year, adres) VALUES ("Andrey", "1999", "mosk6");

INSERT INTO Subjects  (name) VALUES ("fizika");
INSERT INTO Subjects  (name) VALUES ("matematika");
INSERT INTO Subjects  (name) VALUES ("geometria");
INSERT INTO Subjects  (name) VALUES ("himia");
INSERT INTO Subjects  (name) VALUES ("literatura");

INSERT INTO Pup  (class_id, person_id) VALUES (1, 1);
INSERT INTO Pup  (class_id, person_id) VALUES (1, 2);
INSERT INTO Pup  (class_id, person_id) VALUES (2, 3);
INSERT INTO Pup  (class_id, person_id) VALUES (3, 4);
INSERT INTO Pup  (class_id, person_id) VALUES (4, 5);

INSERT INTO Teachers(person_id, subject_id) VALUES(6, 1);
INSERT INTO Teachers(person_id, subject_id) VALUES(6, 2);
INSERT INTO Teachers(person_id, subject_id) VALUES(6, 3);




UPDATE Classes SET number = 2 WHERE id = 4;

UPDATE Pup SET class_id = 
	(
		SELECT  id 
		FROM Classes 
		WHERE 
		number = 1 AND 
		litera = "B"
		GROUP BY 1
	) 

WHERE Pup.person_id = (
	SELECT   id 
	FROM Persons 
	WHERE name = "Ivanov"
	GROUP BY 1
	);