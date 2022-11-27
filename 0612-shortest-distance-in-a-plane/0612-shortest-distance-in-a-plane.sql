select round(sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)), 2) as shortest
from Point2D p1, Point2D p2
where not (p1.x = p2.x and p1.y = p2.y)
order by shortest
limit 1;
