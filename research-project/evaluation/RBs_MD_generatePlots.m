for pairs = 1:5

    folder = {['/home/kunterbunt/dev/omnetpp-5.0/samples/research-project/research-project/results/RBs-MD/' num2str(pairs) 'pairs/']};   

    titles = {['scheduler=MD pairs=' num2str(pairs) ' RBs=50']};

    RBs_generatePlotForFolder(folder{1}, titles(1));    
end