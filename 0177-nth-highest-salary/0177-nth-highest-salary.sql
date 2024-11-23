CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  -- Declare a variable to store the offset
  -- We subtract 1 from N since LIMIT offset starts from 0
  DECLARE offset_value INT;
  SET offset_value = N - 1;
  
  RETURN (
    -- Using DISTINCT to handle duplicate salaries
    -- Using ORDER BY with DESC to get salaries in descending order
    -- Using LIMIT with offset to get the Nth highest salary
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET offset_value
  );
END