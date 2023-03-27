SELECT DISTINCT CITY  FROM STATION WHERE left (CITY , 1) NOT IN ('a', 'e', 'i', 'o', 'u') 
OR right (CITY , 1) NOT IN ('a', 'e', 'i', 'o', 'u')
