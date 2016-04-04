function [resultz] = ps_text (call_count)
    resultz = network_array(call_count, :);
% resultz = zeros(1, 6);
% 
% text = fopen('network_error_delay.txt');
% line_num=1;
% result = fgets(text);
% while ischar(result)
%     if line_num == call_count
%         resultz = str2num(result);
%         break;
%     end
%     result = fgets(text);
%     line_num = line_num+1;
% end
% fclose(text);