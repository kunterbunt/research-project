function generatePlotForFolder(path)
sums = [];
fairnesses = [];
for i=4:50
   filename = [path num2str(i) '/parsed'];
   values = getValuesFromFile(filename);
   sums(end + 1) = sum(values);   
   fairnesses(end + 1) = getFairness(values');
   %label = strcat('Rx', num2str(i));
   %nlabels(end + 1) = {label};
end

figure
hold on
title('Throughput and fairness for 2 D2D pairs and 4 bands');
[hAx,hLine1,hLine2] = plotyy([4:50], sums, [4:50], fairnesses);
ylabel(hAx(1),'#bytes received') % left y-axis 
ylabel(hAx(2),'Jains Fairness Index') % right y-axis
hold off
end

