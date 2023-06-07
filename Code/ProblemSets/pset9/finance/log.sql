-- finance.db Schema
CREATE TABLE IF NOT EXISTS "users" (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
    username TEXT NOT NULL, 
    hash TEXT NOT NULL, 
    cash NUMERIC NOT NULL DEFAULT 10000.00
);
CREATE TABLE sqlite_sequence(name,seq);
CREATE UNIQUE INDEX username ON users (username);

CREATE TABLE IF NOT EXISTS "history" (
    transaction_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
    user_id INTEGER NOT NULL,
    symbol TEXT NOT NULL, 
    shares INTEGER NOT NULL, 
    method TEXT NOT NULL, 
    price REAL NOT NULL, 
    transacted TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users (id)
);

-- CREATE TABLE "portfolio" (
--     user_id INTEGER NOT NULL,
--     symbol TEXT NOT NULL,
--     shares INTEGER NOT NULL,
--     PRIMARY KEY (user_id, symbol)
--     FOREIGN KEY (user_id) REFERENCES users (id)
-- );

-- Check shares
