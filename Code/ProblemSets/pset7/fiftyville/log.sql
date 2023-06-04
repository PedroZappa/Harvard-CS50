-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Query 0
-- Check crime_scene_reports from the July 28th, 2021 for leads
.headers on 
SELECT * 
    FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

id|year|month|day|street|description
295|2021|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
297|2021|7|28|Humphrey Street|Littering took place at 16:36. No known witnesses.


-- Query 1
-- Check bakery_security_logs from the July 28th, 2021 for a licence_plate
.headers on 
SELECT * 
    FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour > 15 AND hour < 17 AND minute > 30;

id|year|month|day|hour|minute|activity|license_plate
284|2021|7|28|16|38|exit|4468KVT
285|2021|7|28|16|42|exit|207W38T
286|2021|7|28|16|47|exit|C194752


-- Query 3
-- Check owners of the license plates registered at the bakery in the half hour after the theft
-- Get name, phone_number, license_plate and passport_number from people
.headers on 
SELECT name, phone_number, passport_number, license_plate 
    FROM people
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 16 AND minute > 30
);

name|phone_number|passport_number|license_plate
Mary|(188) 555-4719||C194752
John|(016) 555-9166|8174538026|4468KVT
Frank|(356) 555-6641|8336437534|207W38T


-- Query 4
-- Join phone_calls made from the phones of the threee suspects
.headers on 
SELECT name, phone_number, passport_number, license_plate, year, month, day, duration 
    FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 16 AND minute > 30
);

name|phone_number|passport_number|license_plate|year|month|day|duration
Mary|(188) 555-4719||C194752|2021|7|25|94
Mary|(188) 555-4719||C194752|2021|7|26|286
Mary|(188) 555-4719||C194752|2021|7|29|223
John|(016) 555-9166|8174538026|4468KVT|2021|7|25|426
John|(016) 555-9166|8174538026|4468KVT|2021|7|28|88
John|(016) 555-9166|8174538026|4468KVT|2021|7|29|175
Frank|(356) 555-6641|8336437534|207W38T|2021|7|30|34
Frank|(356) 555-6641|8336437534|207W38T|2021|7|30|224
Frank|(356) 555-6641|8336437534|207W38T|2021|7|31|395


-- Query 5
-- Cross check phone_calls made at the time of the robbery with the phone_numbers related to the license_plates
.headers on 
SELECT name, phone_number, passport_number, license_plate, year, month, day, duration 
    FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 16 AND minute > 30
) AND phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28;

id|name|phone_number|passport_number|license_plate|year|month|day|duration
677698|John|(016) 555-9166|8174538026|4468KVT|2021|7|28|88

-- John was the only suspect making a phone call at the time of the theft


-- Query 6
-- Cross check phone_calls received at the time of the robbery with the phone_numbers related to the license_plates
.headers on 
SELECT name, phone_number, passport_number, license_plate, year, month, day, duration 
    FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 16 AND minute > 30
) AND phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28;

-- There three suspects received no phone calls around the time of the robbery


-- Query 7
-- Check interviews from the July 28th, 2021
.headers on 
SELECT * 
    FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;

id|name|year|month|day|transcript
158|Jose|2021|7|28|“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
159|Eugene|2021|7|28|“I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”
160|Barbara|2021|7|28|“You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.

161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's' bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

191|Lily|2021|7|28|Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.


-- Query 8 
-- Check for phone_calls shorter than 60 seconds and check if any of them called the owner of the licence_plates at the bakery
.headers on 
SELECT phone_calls.id AS call_id, caller, receiver, duration, people.id AS person_id, people.name, phone_number, passport_number 
    FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 16 AND minute > 30
) AND year = 2021 AND month = 7 AND day = 28;

call_id|caller|receiver|duration|person_id|name|phone_number|passport_number
266|(016) 555-9166|(336) 555-0077|88|677698|John|(016) 555-9166|8174538026

-- John, the owner of the license plate was the one calling the main robber


-- Query 9
-- Get the person being calledby John (receiver)
.headers on 
SELECT *
    FROM people
WHERE phone_number = "(336) 555-0077";

id|name|phone_number|passport_number|license_plate
650560|Rose|(336) 555-0077|8909375052|O7JQ1SA


-- Query 10
-- Get John's bank account number 
.headers on 
SELECT people.name, bank_accounts.account_number
    FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE people.id = "677698";

name|account_number
John|39774254


-- Query 11
-- Get atm_transactions from John's bank account
.headers on 
SELECT *
    FROM atm_transactions
WHERE account_number = "39774254" AND year = 2021 AND month = 7 AND day > 27;

id|account_number|year|month|day|atm_location|transaction_type|amount
377|39774254|2021|7|29|Humphrey Lane|withdraw|30
390|39774254|2021|7|29|Daboin Sanchez Drive|withdraw|25
705|39774254|2021|7|30|Humphrey Lane|withdraw|55
764|39774254|2021|7|30|Leggett Street|withdraw|40


-- Query 12
-- Check what fligh Rose escaped on
.headers on
SELECT flight_id, passport_number, destination_airport_id, flights.year, flights.day, hour
    FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE passport_number = "8909375052" 
    AND year = 2021
    AND month = 7;

flight_id|passport_number|destination_airport_id|year|day|hour
15|8909375052|1|2021|27|7
52|8909375052|8|2021|27|22

-- Rose is a passenger on both flight 15 and 52


-- Query 13
-- Check what's the destinantion of flights 15 and 52
.headers on
SELECT *
    FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE year = 2021
    AND month = 7
    AND flights.id = 15;

id|origin_airport_id|destination_airport_id|year|month|day|hour|minute|id|abbreviation|full_name|city
15|8|1|2021|7|27|7|54|1|ORD|O'Hare International Airport|Chicago'


-- Query 14
-- Check what's the destinantion of flights 52
.headers on
SELECT *
    FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE year = 2021
    AND month = 7
    AND flights.id = 52;
=
id|origin_airport_id|destination_airport_id|year|month|day|hour|minute|id|abbreviation|full_name|city
52|3|8|2021|7|27|22|19|8|CSF|Fiftyville Regional Airport|Fiftyville


-- Query 15
-- Check John's withdrawl of money from atm_transactions
.headers on
SELECT *
    FROM atm_transactions
    WHERE account_number = "39774254" 
        AND year = 2021 
        AND month = 7 
        AND day > 27;

id|account_number|year|month|day|atm_location|transaction_type|amount
377|39774254|2021|7|29|Humphrey Lane|withdraw|30
390|39774254|2021|7|29|Daboin Sanchez Drive|withdraw|25
705|39774254|2021|7|30|Humphrey Lane|withdraw|55
764|39774254|2021|7|30|Leggett Street|withdraw|40


-- Query 16
-- get Rose id and background info
.headers on
SELECT *
    FROM people
WHERE name = "Rose";

id|name|phone_number|passport_number|license_plate
650560|Rose|(336) 555-0077|8909375052|O7JQ1SA


-- Query 17
-- get Rose's bank info
.headers on
SELECT *
    FROM bank_accounts
WHERE person_id = "650560";

account_number|person_id|creation_year
19531272|650560|2012


-- Query 18
-- get Roses atm transactions
.headers on
SELECT *
    FROM atm_transactions
WHERE account_number = "19531272" 
    AND year = 2021 
    AND month = 7 
    AND day > 27;


id|account_number|year|month|day|atm_location|transaction_type|amount
263|19531272|2021|7|28|Blumberg Boulevard|withdraw|55
438|19531272|2021|7|29|Humphrey Lane|withdraw|25
740|19531272|2021|7|30|Daboin Sanchez Drive|deposit|95
897|19531272|2021|7|31|Carvalho Road|withdraw|100
904|19531272|2021|7|31|Daboin Sanchez Drive|withdraw|30

--
--
--

-- Query 0
-- Check crime reports on Humphrey Street
.headers on
SELECT * 
   FROM crime_scene_reports
WHERE street = 'Humphrey Street';

id|year|month|day|street|description
80|2021|2|26|Humphrey Street|Theft took place at 03:11. Two people witnessed the event.
113|2021|3|20|Humphrey Street|Credit card fraud took place at 08:41. One person witnessed the incident.
128|2021|4|4|Humphrey Street|Expired parking meter took place at 03:17. Two people witnessed the event.
254|2021|7|6|Humphrey Street|Shoplifting took place at 04:45. Two people witnessed the event.
295|2021|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
297|2021|7|28|Humphrey Street|Littering took place at 16:36. No known witnesses.
299|2021|7|30|Humphrey Street|Littering took place at 17:49. Two people witnessed the event.

-- Bakery is the location of the robbery
-- Every witness mentions the bakery

-- Query 1
-- Get interviews from witnesses
.headers on
SELECT * 
   FROM interviews
WHERE transcript LIKE '%bakery%'
    AND year = 2021
    AND month = 7
    AND day = 28;

id|name|year|month|day|transcript
161|Ruth|2021|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
162|Eugene|2021|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's' bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
163|Raymond|2021|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- thief was out of the bakery at 10:15
-- Ruth talks about the bakery footage
-- eugene talks about somebody at the ATM
-- Raymond short phone call and a flight ticket


-- Query 2
-- Ruth talked about the bakery footage for licence plate
.headers on
SELECT * 
   FROM bakery_security_logs 
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15;

id|year|month|day|hour|minute|activity|license_plate
260|2021|7|28|10|16|exit|5P2BI95
261|2021|7|28|10|18|exit|94KL13X
262|2021|7|28|10|18|exit|6P58WS2
263|2021|7|28|10|19|exit|4328GD8
264|2021|7|28|10|20|exit|G412CB7
265|2021|7|28|10|21|exit|L93JTIZ
266|2021|7|28|10|23|exit|322W7JE
267|2021|7|28|10|23|exit|0NTHK55


-- Query 3
-- Check license plates
.headers on
SELECT people.name, bakery_security_logs.activity, bakery_security_logs.license_plate, bakery_security_logs.year, bakery_security_logs.month, bakery_security_logs.day, bakery_security_logs.hour, bakery_security_logs.minute
    FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute BETWEEN 15 AND 25;

name|activity|license_plate|year|month|day|hour|minute
Vanessa|exit|5P2BI95|2021|7|28|10|16
Bruce|exit|94KL13X|2021|7|28|10|18
Barry|exit|6P58WS2|2021|7|28|10|18
Luca|exit|4328GD8|2021|7|28|10|19
Sofia|exit|G412CB7|2021|7|28|10|20
Iman|exit|L93JTIZ|2021|7|28|10|21
Diana|exit|322W7JE|2021|7|28|10|23
Kelsey|exit|0NTHK55|2021|7|28|10|23

--


-- Query 4
-- Check atm logs
.headers on
SELECT *    
    FROM atm_transactions
WHERE atm_location = "Leggett Street" 
    AND year = 2021 
    AND month = 7 
    AND day = 28;

id|account_number|year|month|day|atm_location|transaction_type|amount
246|28500762|2021|7|28|Leggett Street|withdraw|48
264|28296815|2021|7|28|Leggett Street|withdraw|20
266|76054385|2021|7|28|Leggett Street|withdraw|60
267|49610011|2021|7|28|Leggett Street|withdraw|50
269|16153065|2021|7|28|Leggett Street|withdraw|80
275|86363979|2021|7|28|Leggett Street|deposit|10
288|25506511|2021|7|28|Leggett Street|withdraw|20
313|81061156|2021|7|28|Leggett Street|withdraw|30
336|26013199|2021|7|28|Leggett Street|withdraw|35


-- Query 5
-- Add name of withdrawn from atm
.headers on
SELECT *    
    FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE atm_location = "Leggett Street" 
    AND year = 2021 
    AND month = 7 
    AND day = 28
    AND atm_transactions.transaction_type = "withdraw";

id|account_number|year|month|day|atm_location|transaction_type|amount|account_number|person_id|creation_year|id|name|phone_number|passport_number|license_plate
267|49610011|2021|7|28|Leggett Street|withdraw|50|49610011|686048|2010|686048|Bruce|(367) 555-5533|5773159633|94KL13X
336|26013199|2021|7|28|Leggett Street|withdraw|35|26013199|514354|2012|514354|Diana|(770) 555-1861|3592750733|322W7JE
269|16153065|2021|7|28|Leggett Street|withdraw|80|16153065|458378|2012|458378|Brooke|(122) 555-4581|4408372428|QX4YZN3
264|28296815|2021|7|28|Leggett Street|withdraw|20|28296815|395717|2014|395717|Kenny|(826) 555-1652|9878712108|30G67EN
288|25506511|2021|7|28|Leggett Street|withdraw|20|25506511|396669|2014|396669|Iman|(829) 555-5269|7049073643|L93JTIZ
246|28500762|2021|7|28|Leggett Street|withdraw|48|28500762|467400|2014|467400|Luca|(389) 555-5198|8496433585|4328GD8
266|76054385|2021|7|28|Leggett Street|withdraw|60|76054385|449774|2015|449774|Taylor|(286) 555-6063|1988161715|1106N58
313|81061156|2021|7|28|Leggett Street|withdraw|30|81061156|438727|2018|438727|Benista|(338) 555-6650|9586786673|8X428L0


-- Query 6
-- Check phone calls
.headers on
SELECT phone_calls.caller, phone_calls.receiver, phone_calls.year, phone_calls.month, phone_calls.day, phone_calls.duration
    FROM phone_calls
WHERE phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60;

id|caller|receiver|year|month|day|duration
221|(130) 555-0289|(996) 555-8899|2021|7|28|51
224|(499) 555-9472|(892) 555-8872|2021|7|28|36
233|(367) 555-5533|(375) 555-8161|2021|7|28|45
251|(499) 555-9472|(717) 555-1342|2021|7|28|50
254|(286) 555-6063|(676) 555-6554|2021|7|28|43
255|(770) 555-1861|(725) 555-3243|2021|7|28|49
261|(031) 555-6622|(910) 555-3251|2021|7|28|38
279|(826) 555-1652|(066) 555-9701|2021|7|28|55
281|(338) 555-6650|(704) 555-2131|2021|7|28|54




-- QUERY 7
-- Add names to call list of callers
.headers on
SELECT people.name, phone_calls.caller, phone_calls.receiver, phone_calls.year, phone_calls.month, phone_calls.day, phone_calls.duration
    FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60;

name|caller|receiver|year|month|day|duration
Sofia|(130) 555-0289|(996) 555-8899|2021|7|28|51
Kelsey|(499) 555-9472|(892) 555-8872|2021|7|28|36
Bruce|(367) 555-5533|(375) 555-8161|2021|7|28|45
Kelsey|(499) 555-9472|(717) 555-1342|2021|7|28|50
Taylor|(286) 555-6063|(676) 555-6554|2021|7|28|43
Diana|(770) 555-1861|(725) 555-3243|2021|7|28|49
Carina|(031) 555-6622|(910) 555-3251|2021|7|28|38
Kenny|(826) 555-1652|(066) 555-9701|2021|7|28|55
Benista|(338) 555-6650|(704) 555-2131|2021|7|28|54


-- Query 8
-- Explore airports looking for Fiftyville
.headers on
SELECT *
    FROM airports;

id|abbreviation|full_name|city
1|ORD|O'Hare' International Airport|Chicago
2|PEK|Beijing Capital International Airport|Beijing
3|LAX|Los Angeles International Airport|Los Angeles
4|LGA|LaGuardia Airport|New York City
5|DFS|Dallas/Fort Worth International Airport|Dallas
6|BOS|Logan International Airport|Boston
7|DXB|Dubai International Airport|Dubai

8|CSF|Fiftyville Regional Airport|Fiftyville

9|HND|Tokyo International Airport|Tokyo
10|CDG|Charles de Gaulle Airport|Paris
11|SFO|San Francisco International Airport|San Francisco
12|DEL|Indira Gandhi International Airport|Delhi

-- Fiftyville ID is 8!


-- Query 9
-- Explore flights out
.headers on
SELECT flights.*, og.full_name AS origin_airport, dest.full_name AS destinantion_airport
    FROM flights
JOIN airports og ON flights.origin_airport_id = og.id
JOIN airports dest ON flights.destination_airport_id = dest.id
WHERE og.id = 8
    AND flights.year = 2021
    AND flights.month = 7
    AND flights.day = 29
ORDER BY flights.hour, flights.minute;

id|origin_airport_id|destination_airport_id|year|month|day|hour|minute|origin_airport|destinantion_airport
36|8|4|2021|7|29|8|20|Fiftyville Regional Airport|LaGuardia Airport
43|8|1|2021|7|29|9|30|Fiftyville Regional Airport|O'Hare' International Airport
23|8|11|2021|7|29|12|15|Fiftyville Regional Airport|San Francisco International Airport
53|8|9|2021|7|29|15|20|Fiftyville Regional Airport|Tokyo International Airport
18|8|6|2021|7|29|16|0|Fiftyville Regional Airport|Logan International Airport

-- He escaped to New York (La Guadia Airport)


-- Query 10
-- combine info from witnesses
.headers on
SELECT people.name  
    FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
JOIN bank_accounts ON  bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE bakery_security_logs.year = 2021
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.hour = 10
    AND bakery_security_logs.minute BETWEEN 15 AND 25
    AND atm_location = "Leggett Street"
    AND phone_calls.year = 2021 
    AND phone_calls.month = 7 
    AND phone_calls.day = 28 
    AND phone_calls.duration < 60;

name
Diana
Bruce


-- Query 11
-- Check who is on flight (Bruce or Diana)
.headers on
SELECT DISTINCT people.name  
    FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = 36
    AND people.name IN ('Bruce', 'Diana');

name
Bruce

-- Bruce was on the flight 36


-- Query 12
-- Who did Bruce call?
.headers on
SELECT receiver.name AS receiver
    FROM phone_calls
JOIN people caller ON phone_calls.caller = caller.phone_number
JOIN people receiver ON phone_calls.receiver = receiver.phone_number
WHERE caller.name = 'Bruce'
    AND phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60;

receiver
Robin


-- Query 13
.headers on
SELECT people.name, phone_calls.caller, receiver.name AS receiver_name, phone_calls.receiver, phone_calls.year, phone_calls.month, phone_calls.day, phone_calls.duration
    FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
JOIN people receiver ON phone_calls.receiver = receiver.phone_number
WHERE phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60
    AND people.name = 'Bruce';


