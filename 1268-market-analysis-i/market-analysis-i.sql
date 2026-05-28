# Write your MySQL query statement below
SELECT 
    u.user_id AS buyer_id #We should use u.user_id instead of o.buyer_id, because when there is no matching order in 2019, o.buyer_id will be NULL, but u.user_id will still hold the actual user’s ID.
    ,u.join_date
    ,IFNULL(COUNT(o.order_id),0) AS orders_in_2019 #Makes sure users with no orders still get 0
FROM users u
LEFT JOIN orders o
    ON u.user_id=o.buyer_id
    AND YEAR(order_date) = '2019'
GROUP BY u.user_id, u.join_date

