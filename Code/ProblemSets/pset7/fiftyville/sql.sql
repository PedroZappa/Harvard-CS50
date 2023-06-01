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
