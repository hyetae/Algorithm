-- 코드를 작성해주세요
SELECT DISTINCT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM SKILLCODES
JOIN DEVELOPERS
ON CODE & SKILL_CODE
WHERE CATEGORY = "Front End"
ORDER BY ID;