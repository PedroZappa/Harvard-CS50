.headers on
SELECT phone_calls.caller, phone_calls.receiver, phone_calls.year, phone_calls.month, phone_calls.day, phone_calls.duration
    FROM phone_calls
WHERE phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60;