function RBs_generatePlotForFolder(path, plotTitle, ylimit)
sums = [];
fairnesses = [];
for i=1:10
   filename = [path num2str(i) 'bands/parsed'];   
   [byteSum, fairness] = getByteSumAndFairness(filename);   
   sums(end + 1) = byteSum;
   fairnesses(end + 1) = fairness;   
end

%fig = figure('visible', 'off');
figure
hold on
title(plotTitle);
[hAx, hLine1, hLine2] = plotyy(1:10, sums, 1:10, fairnesses);
ylabel(hAx(1),'#bytes received') % left y-axis 
ylabel(hAx(2),'Jains Fairness Index') % right y-axis
if exist('ylimit', 'var')    
    set(gca,'ylim', ylimit)
end
set(hAx(2),'YLim',[0 1.1])
set(gca,'fontsize', 21)
set(hAx(2),'fontsize', 21)
xlabel('#bands');

%ylabh = get(hAx(2),'ylabel');
%set(ylabh,'Position', get(ylabh,'Position') + [-2 0 0])

%xlabh = get(gca, 'xlabel');
%set(xlabh,'Position', [5 0 0])

%titleh = get(gca, 'title');
%set(titleh, 'Position', get(titleh,'Position') + [1 0 0])

hold off
%filename = strcat(path, plotTitle, '.png');
%saveas(fig, filename{1}, 'png');
end

