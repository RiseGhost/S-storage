all: storage.c
	@echo "🔨 Building app"
	@gcc -o storage storage.c
	@echo "✅ finished"

clean:
	@rm storage