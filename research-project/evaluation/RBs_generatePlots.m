for pairs = 1:5

    folder = {['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/RBs/' num2str(pairs) 'pairs/']};   

    titles = {['DRR-Scheduler--' num2str(pairs) 'pairs--50RBs']};

    RBs_generatePlotForFolder(folder{1}, titles(1));    
end