function plotFile(path, labels)
    parts = strsplit(path, '/');
    dir = parts{end-1};
    filename = [path 'parsed'];
    values = getValuesFromFile(filename);
    plot = bar(values);
    axis([0, size(labels, 1) + 1,0,3200000])
    ylabel('#packets received');
    set(gca, 'XTick', 1:3, 'XTickLabel', labels);    
    title(dir);
    saveas(plot, [path dir '.png'],'png');
end

