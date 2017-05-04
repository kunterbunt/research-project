for pairs = 1:5

    folder = {['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/RBs-MD/' num2str(pairs) 'pairs/']};   

    titles = {['MD-Scheduler--' num2str(pairs) 'pairs--50RBs']};

    RBs_generatePlotForFolder(folder{1}, titles(1));    
end