function [resultz] = ps_aggregation (call_count)

resultz = zeros(1, 18);
countz = 1;

for i_pa = 1 : call_count
    %disp('emergency instance');
    %disp(emergency_instance)
    %disp('i_pa: ')
    %disp(i_pa);
    [result status]=python('tossim-event-client-ps.py');
    %disp(result);
    if i_pa == 51
        resultz=str2num(result);
        disp('result: ');
        disp(resultz);
    end
end