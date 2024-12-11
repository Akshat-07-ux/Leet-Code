# Write your MySQL query statement below
SELECT W1.id
FROM Weather W1
JOIN Weather W2
ON DATE_ADD(W2.recordDate, INTERVAL 1 DAY) = W1.recordDate
WHERE W1.temperature > W2.temperature;
