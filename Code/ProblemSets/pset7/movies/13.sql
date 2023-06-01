-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred (excluding Kevin Bacon himself).
SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN (
    SELECT DISTINCT movie_id from stars
    JOIN people ON stars.person_id = people.id
    WHERE people.name = "Kevin Bacon"
    AND people.birth = 1958)
AND people.name != "Kevin Bacon";