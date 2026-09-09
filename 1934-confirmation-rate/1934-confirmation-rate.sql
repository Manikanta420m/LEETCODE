SELECT s.user_id ,
    ROUND(
        AVG(
           IF(c.action = 'confirmed',1.00,0)
        ),
        2
    ) confirmation_rate
FROM Signups s
LEFT JOIN
     Confirmations c
     On 
     s.user_id = c.user_id
GROUP BY
     s.user_id