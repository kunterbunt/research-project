folder = {['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/BandEffect-D2D-50RB-MD/']};   
titles = {['Max Datarate Scheduler: Band study, 50 RBs total']};  

sums = [];
fairnesses = [];
for i=1:10
   filename = [folder{1} num2str(i) 'bands/parsed'];   
   [byteSum, fairness] = getByteSumAndFairness(filename);   
   sums(end + 1) = byteSum;
   fairnesses(end + 1) = fairness;   
end

%fig = figure('visible', 'off');
figure
hold on
title(titles(1));
[hAx, hLine1, hLine2] = plotyy(1:10, sums, 1:10, fairnesses);
ylabel(hAx(1),'#bytes received') % left y-axis 
ylabel(hAx(2),'Jains Fairness Index') % right y-axis     
%set(gca,'XTickLabel', ['1 pair', '2 pairs', '3 pairs', '4 pairs', '5 pairs'])
set(hAx(1),'YLim',[0 1E8])
set(hAx(2),'YLim',[0 1.1])
set(gca,'fontsize', 21)
xlabel('#bands');  
set(hAx(2),'fontsize', 21)
hold off