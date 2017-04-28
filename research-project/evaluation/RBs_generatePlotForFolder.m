function RBs_generatePlotForFolder(path, plotTitle)
sums = [];
fairnesses = [];
for i=1:10
   filename = [path num2str(i) 'bands/parsed'];   
   [byteSum, fairness] = getByteSumAndFairness(filename);   
   sums(end + 1) = byteSum;
   fairnesses(end + 1) = fairness;   
end

fig = figure;
%figure
hold on
title(plotTitle);
[hAx, hLine1, hLine2] = plotyy(1:10, sums, 1:10, fairnesses);
ylabel(hAx(1),'#bytes received') % left y-axis 
ylabel(hAx(2),'Jains Fairness Index') % right y-axis
set(hAx(1),'YLim',[0 8000000])
set(hAx(2),'YLim',[0 1.1])
%set(hAx,'xlim', rbs);
xlabel('number of Bands');
hold off
%filename = strcat(path, plotTitle, '.png');
%saveas(fig, filename{1}, 'png');
end

