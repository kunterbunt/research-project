function plotValues(values, titles)
figure;
hold on;
bar(values);
axis([0,9,0,3500000])
set(gca,'XTickLabel', titles);
set(gca,'XTickLabelRotation', 45);
hold off;
end