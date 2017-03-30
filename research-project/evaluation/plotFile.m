function plotFile(path, labels)
    filename = [path 'parsed'];
    values = getValuesFromFile(filename);
%     figure;
%     hold on;
    plot = bar(values);
    axis([0, size(labels, 1) + 1,0,3200000])
    set(gca, 'XTick', 1:3, 'XTickLabel', labels);    
%     hold off;
    parts = strsplit(path, '/');
    dir = parts{end-1};
    saveas(plot, [path dir '.png'],'png');
end

