select t1.id, "Root" as Type from tree t1 where t1.p_id is null
union
select t1.id, "Inner" as Type from tree t1 left join tree t2 on t1.id = t2.p_id where t2.p_id is not null and t1.p_id is not null
union
