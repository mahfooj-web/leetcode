CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  -- Adjust N because OFFSET is 0-indexed
  -- e.g. for N = 1 (highest), we want OFFSET 0
  --      for N = 2 (2nd highest), we want OFFSET 1
  SET N = N - 1;

  RETURN (
      -- Step 1: Get all DISTINCT salaries (duplicates should not
      -- occupy separate "ranks", e.g. [100,100,90] -> 2nd highest is 90)
      SELECT DISTINCT Salary
      FROM Employee
      -- Step 2: Sort salaries from highest to lowest so that
      -- row 0 = 1st highest, row 1 = 2nd highest, etc.
      ORDER BY Salary DESC
      -- Step 3: Skip the first N salaries and take just 1 row
      -- (LIMIT 1 OFFSET N -> the (N+1)-th row in the sorted list)
      LIMIT 1 OFFSET N
  );
  -- If N is negative or too large, OFFSET goes out of range and the
  -- subquery returns no rows, so MySQL implicitly returns NULL
  -- (exactly the behavior the problem wants)
END