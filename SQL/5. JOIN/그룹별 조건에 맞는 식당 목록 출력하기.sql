﻿SELECT M.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM MEMBER_PROFILE AS M
INNER JOIN REST_REVIEW AS R
ON M.MEMBER_ID = R.MEMBER_ID
WHERE R.MEMBER_ID = (
    -- 최대 개수에 해당하는 회원ID 구하기
    SELECT MEMBER_ID
    FROM REST_REVIEW
    GROUP BY MEMBER_ID
    ORDER BY COUNT(MEMBER_ID) DESC -- COUNT값 기준 내림차순 정렬 후
    LIMIT 1 -- 가장 위에 있는 행 선택
)
ORDER BY REVIEW_DATE ASC, REVIEW_TEXT ASC;