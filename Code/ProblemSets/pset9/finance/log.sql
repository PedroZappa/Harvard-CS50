-- finance.db Schema
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
    username TEXT NOT NULL, 
    hash TEXT NOT NULL, 
    cash NUMERIC NOT NULL DEFAULT 10000.00
);

CREATE TABLE sqlite_sequence(name,seq);

CREATE UNIQUE INDEX username ON users (username);

CREATE TABLE IF NOT EXISTS history (
    transaction_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
    user_id INTEGER NOT NULL,
    symbol TEXT NOT NULL, 
    shares INTEGER NOT NULL, 
    method TEXT NOT NULL, 
    price NUMERIC NOT NULL, 
    transacted TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
    FOREIGN KEY(user_id) REFERENCES users(id)
);



-- Check Users
.headers ON
SELECT id, username, cash
    FROM users;

id|username|cash
1|Zed|7574.47


-- Check History
.headers ON
SELECT user_id, symbol, shares, method, price, transacted
    FROM history;

id|username|cash
1|Zed|7574.47



-- Check Users and History
.headers ON
SELECT id, username, cash, history.symbol, history.shares, history.price, history.transacted
    FROM users
JOIN history ON users.id = history.user_id;

id|username|cash|symbol|shares|price|transacted
1|Zedro|8787.38|ZZZ|1000|0.01|2023-06-07 19:29:53
1|Zedro|8787.38|ZZZ|100|0.01|2023-06-07 19:30:02
1|Zedro|8787.38|NFLX|3|400.54|2023-06-07 19:33:55


-- Check Users and History with sum_shares
.headers ON
SELECT id, username, cash, SUM(history.shares) AS sum_shares
    FROM users
JOIN history ON users.id = history.user_id;

id|username|cash|sum_shares
1|Zedro|8787.38|1103


-- Check Users and History with sum_shares filtering only ZZZ
.headers ON
SELECT id, username, cash, SUM(history.shares) AS sum_shares
    FROM users
JOIN history ON users.id = history.user_id
WHERE history.symbol = 'ZZZ';

id|username|cash|sum_shares
1|Zedro|8787.38|1100


--  Check total stocks for user
.headers ON
SELECT symbol, SUM(shares) AS sum_shares
    FROM history
WHERE users.id = 1
GROUP BY symbol HAVING sum_shares > 0;

symbol|sum_shares
NFLX|3
T|8
ZZZ|1400
