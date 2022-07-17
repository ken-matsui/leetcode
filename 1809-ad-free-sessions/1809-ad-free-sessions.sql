select session_id
from Playback
where not exists (
    select timestamp
    from Ads
    where Playback.customer_id = Ads.customer_id
      and timestamp between start_time and end_time
);
