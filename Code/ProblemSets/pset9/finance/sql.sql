.headers ON
SELECT symbol, SUM(shares) AS sum_shares
    FROM users
JOIN history ON users.id = history.user_id
WHERE users.id = 2
GROUP BY symbol HAVING sum_shares > 0;