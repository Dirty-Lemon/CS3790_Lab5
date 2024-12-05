TARGET= banker
$(TARGET) : $(TARGET).cpp
	g++ $(TARGET).cpp -o $(TARGET)

.PHONY: clean
clean:
	rm -i $(TARGET)