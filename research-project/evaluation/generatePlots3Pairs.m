for pairs = 2:5

    folders = {['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/1bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/2bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/3bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/4bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/5bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/6bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/7bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/8bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/9bands/'];
        ['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/ComplexSim-MD/' num2str(pairs) 'pairs/10bands/']};

    rbs = [[1 11]; [2 12]; [3 13]; [4 14]; [5 15]; [6 16]; [7 17]; [8 18]; [9 19]; [10 20]];

    titles = {['pairs=' num2str(pairs) ' bands=1'], ['pairs=' num2str(pairs) ' bands=2'], ['pairs=' num2str(pairs) ' bands=3'], ['pairs=' num2str(pairs) ' bands=4'], ['pairs=' num2str(pairs) ' bands=5'], ['pairs=' num2str(pairs) ' bands=6'], ['pairs=' num2str(pairs) ' bands=7'], ['pairs=' num2str(pairs) ' bands=8'], ['pairs=' num2str(pairs) ' bands=9'], ['pairs=' num2str(pairs) ' bands=10']};

    for i=1:size(folders)       
        rb = [rbs(i,1) rbs(i,2)];        
        generatePlotForFolder(folders{i}, rb, titles(i));    
    end
end