%decisionMaking

if (ADC12_LS > thresh_LEFT)
    leftClear = false;
else
    leftClear = true;
end

if (ADC11_RS > thresh_RIGHT)
    rightClear = false;
else
    rightClear = true;
end

if (ADC14_FWD_LS > init_FWD_LEFT &&  ADC9_FWD_RS > init_FWD_RIGHT)
    wallAhead = true;
else
    wallAhead = false;
end
%Decision Making Algorithm

if (~wallAhead && ~rightClear && ~leftClear)
    crossroadCondition = 1; % Case for going straight
elseif (~leftClear && rightClear && wallAhead)
    crossroadCondition = 2;  % Case for turning right (count as straight in memory)
elseif (~rightClear && wallAhead && leftClear)
    crossroadCondition = 3;  % Case for turning left (count as straight in memory)
elseif (~leftClear && wallAhead && ~rightClear)
    crossroadCondition = 4;  % Case for turning back
elseif (rightClear && leftClear && wallAhead)
    crossroadCondition = 5; % Case for turning left
elseif (leftClear && ~rightClear && ~wallAhead)
    crossroadCondition = 6; % Case for turning left
else
    crossroadCondition = 7;  % Final case for going straight
end
