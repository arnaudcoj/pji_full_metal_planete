.PHONY: clean All

All:
	@echo "----------Building project:[ tests - Debug ]----------"
	@cd "tests" && "$(MAKE)" -f  "tests.mk"
clean:
	@echo "----------Cleaning project:[ tests - Debug ]----------"
	@cd "tests" && "$(MAKE)" -f  "tests.mk" clean
