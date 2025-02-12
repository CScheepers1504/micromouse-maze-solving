function optimized_path = optimize_path(input_path)
    % This function takes a 1D array of integers as input and applies
    % optimization rules repeatedly until no further optimizations can be applied.
    
    % input_path is a 1D array of integers: 1=R, 2=S, 3=L, 4=B
    % optimized_path will be the same 1D array after applying rules, filled with zeros initially
    
    % Initial setup
    previous_path = input_path; 
    optimized_path = zeros(size(input_path)); % Preallocate the optimized path
    
    % Keep applying optimization until the path no longer changes
    while true
        % Index for the optimized path
        opt_index = 1;
        i = 1;
        
        % Traverse the path and apply the replacement rules
        while i <= length(previous_path)
            % Check if there are enough elements left to apply a rule (3 elements)
            if i <= length(previous_path) - 2
                % Check for LBR -> B (3 4 1 -> 4)
                if isequal(previous_path(i:i+2), [3, 4, 1])
                    optimized_path(opt_index) = 4;  % Replace with B
                    i = i + 3;  % Move forward by 3 elements in the input path
                % Check for RBL -> B (1 4 3 -> 4)
                elseif isequal(previous_path(i:i+2), [1, 4, 3])
                    optimized_path(opt_index) = 4;  % Replace with B
                    i = i + 3;
                % Check for SBS -> B (2 4 2 -> 4)
                elseif isequal(previous_path(i:i+2), [2, 4, 2])
                    optimized_path(opt_index) = 4;  % Replace with B
                    i = i + 3;
                % Check for RBS -> L (1 4 2 -> 3)
                elseif isequal(previous_path(i:i+2), [1, 4, 2])
                    optimized_path(opt_index) = 3;  % Replace with L
                    i = i + 3;
                % Check for SBR -> L (2 4 1 -> 3)
                elseif isequal(previous_path(i:i+2), [2, 4, 1])
                    optimized_path(opt_index) = 3;  % Replace with L
                    i = i + 3;
                % Check for LBL -> S (3 4 3 -> 2)
                elseif isequal(previous_path(i:i+2), [3, 4, 3])
                    optimized_path(opt_index) = 2;  % Replace with S
                    i = i + 3;
                % Check for RBR -> S (1 4 1 -> 2)
                elseif isequal(previous_path(i:i+2), [1, 4, 1])
                    optimized_path(opt_index) = 2;  % Replace with S
                    i = i + 3;
                else
                    % If no rule is applied, just copy the current element
                    optimized_path(opt_index) = previous_path(i);
                    i = i + 1;  % Move to the next element in input path
                end
            else
                % For the last 2 or fewer elements, just copy them directly
                optimized_path(opt_index) = previous_path(i);
                i = i + 1;  % Move to the next element in input path
            end
            
            % Increment the index for the optimized path
            opt_index = opt_index + 1;
        end
        
        % If no changes were made, break the loop
        if isequal(previous_path, optimized_path)
            break;
        end
        
        % Update previous_path for the next iteration
        previous_path = optimized_path;
        optimized_path = zeros(size(previous_path)); % Reset optimized path
    end
end
