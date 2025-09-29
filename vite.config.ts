import { defineConfig } from 'vite';

export default defineConfig({
	base: './',
	server: {
		port: 3002
	},
	build: {
		outDir: 'dist',
		emptyOutDir: true,
		rollupOptions: {
			output: {
				entryFileNames: 'assets/app.js',
				chunkFileNames: 'assets/[name].js',
				assetFileNames: 'assets/[name][extname]'
			}
		}
	}
});

