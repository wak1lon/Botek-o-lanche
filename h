<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cardápio Hamburgueria Delícia</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
    <style>
        :root {
            --primary-color: #FF6B00;
            --secondary-color: #FFA726;
            --dark-color: #333;
            --light-color: #f9f9f9;
            --success-color: #4CAF50;
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }
        
        body {
            background-color: #f5f5f5;
            color: var(--dark-color);
            line-height: 1.6;
        }
        
        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 0 15px;
        }
        
        /* Header */
        header {
            background: linear-gradient(rgba(0, 0, 0, 0.7), rgba(0, 0, 0, 0.7)), url('https://images.unsplash.com/photo-1586190848861-99aa4a171e90?ixlib=rb-1.2.1&auto=format&fit=crop&w=1350&q=80');
            background-size: cover;
            background-position: center;
            color: white;
            text-align: center;
            padding: 2rem 0;
            position: relative;
        }
        
        .banner-content {
            position: relative;
            z-index: 2;
        }
        
        .logo {
            font-size: 2.5rem;
            font-weight: bold;
            margin-bottom: 1rem;
            color: var(--primary-color);
        }
        
        .slogan {
            font-size: 1.2rem;
            margin-bottom: 1.5rem;
        }
        
        /* Mesa QR/NFC */
        .table-section {
            background-color: var(--dark-color);
            color: white;
            padding: 1rem;
            text-align: center;
            margin-bottom: 2rem;
        }
        
        .table-info {
            display: flex;
            justify-content: center;
            align-items: center;
            gap: 1rem;
            flex-wrap: wrap;
        }
        
        .qr-btn, .nfc-btn {
            background-color: var(--primary-color);
            color: white;
            border: none;
            padding: 0.5rem 1rem;
            border-radius: 5px;
            cursor: pointer;
            display: flex;
            align-items: center;
            gap: 0.5rem;
            font-weight: bold;
        }
        
        /* Menu Categories */
        .menu-categories {
            display: flex;
            overflow-x: auto;
            gap: 0.5rem;
            padding: 1rem 0;
            margin-bottom: 1rem;
            scrollbar-width: none;
        }
        
        .menu-categories::-webkit-scrollbar {
            display: none;
        }
        
        .category-btn {
            background-color: white;
            border: 1px solid #ddd;
            padding: 0.5rem 1rem;
            border-radius: 20px;
            cursor: pointer;
            white-space: nowrap;
            transition: all 0.3s;
        }
        
        .category-btn.active, .category-btn:hover {
            background-color: var(--primary-color);
            color: white;
            border-color: var(--primary-color);
        }
        
        /* Menu Items */
        .menu-items {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
            gap: 1.5rem;
            margin-bottom: 3rem;
        }
        
        .menu-item {
            background-color: white;
            border-radius: 10px;
            overflow: hidden;
            box-shadow: 0 3px 10px rgba(0, 0, 0, 0.1);
            transition: transform 0.3s;
        }
        
        .menu-item:hover {
            transform: translateY(-5px);
        }
        
        .item-image {
            width: 100%;
            height: 200px;
            object-fit: cover;
        }
        
        .item-details {
            padding: 1rem;
        }
        
        .item-header {
            display: flex;
            justify-content: space-between;
            margin-bottom: 0.5rem;
        }
        
        .item-name {
            font-weight: bold;
            font-size: 1.2rem;
        }
        
        .item-price {
            color: var(--primary-color);
            font-weight: bold;
        }
        
        .item-description {
            color: #666;
            margin-bottom: 1rem;
            font-size: 0.9rem;
        }
        
        .item-footer {
            display: flex;
            justify-content: space-between;
            align-items: center;
        }
        
        .add-to-cart {
            background-color: var(--primary-color);
            color: white;
            border: none;
            padding: 0.5rem 1rem;
            border-radius: 5px;
            cursor: pointer;
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }
        
        .highlight-badge {
            background-color: var(--secondary-color);
            color: white;
            padding: 0.2rem 0.5rem;
            border-radius: 5px;
            font-size: 0.8rem;
            font-weight: bold;
        }
        
        /* Featured Section */
        .featured-section {
            margin: 2rem 0;
            padding: 1.5rem;
            background-color: var(--secondary-color);
            color: white;
            border-radius: 10px;
            text-align: center;
        }
        
        .featured-title {
            font-size: 1.5rem;
            margin-bottom: 1rem;
        }
        
        /* Admin Panel */
        .admin-panel {
            position: fixed;
            bottom: 20px;
            right: 20px;
            z-index: 1000;
        }
        
        .admin-btn {
            background-color: var(--dark-color);
            color: white;
            width: 50px;
            height: 50px;
            border-radius: 50%;
            display: flex;
            justify-content: center;
            align-items: center;
            cursor: pointer;
            box-shadow: 0 3px 10px rgba(0, 0, 0, 0.2);
        }
        
        .admin-options {
            position: absolute;
            bottom: 60px;
            right: 0;
            background-color: white;
            border-radius: 10px;
            box-shadow: 0 3px 10px rgba(0, 0, 0, 0.2);
            padding: 1rem;
            display: none;
            width: 250px;
        }
        
        .admin-options.show {
            display: block;
        }
        
        .admin-option {
            padding: 0.5rem 0;
            border-bottom: 1px solid #eee;
            cursor: pointer;
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }
        
        .admin-option:last-child {
            border-bottom: none;
        }
        
        /* WhatsApp Button */
        .whatsapp-btn {
            position: fixed;
            bottom: 20px;
            left: 20px;
            background-color: #25D366;
            color: white;
            width: 60px;
            height: 60px;
            border-radius: 50%;
            display: flex;
            justify-content: center;
            align-items: center;
            cursor: pointer;
            box-shadow: 0 3px 10px rgba(0, 0, 0, 0.2);
            z-index: 1000;
            font-size: 2rem;
            text-decoration: none;
        }
        
        /* Footer */
        footer {
            background-color: var(--dark-color);
            color: white;
            text-align: center;
            padding: 2rem 0;
            margin-top: 2rem;
        }
        
        .contact-info {
            margin-bottom: 1rem;
        }
        
        .social-links {
            display: flex;
            justify-content: center;
            gap: 1rem;
            margin-bottom: 1rem;
        }
        
        .social-link {
            color: white;
            font-size: 1.5rem;
        }
        
        .copyright {
            font-size: 0.9rem;
            color: #aaa;
        }
        
        /* Modal */
        .modal {
            display: none;
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-color: rgba(0, 0, 0, 0.7);
            z-index: 2000;
            justify-content: center;
            align-items: center;
        }
        
        .modal.show {
            display: flex;
        }
        
        .modal-content {
            background-color: white;
            border-radius: 10px;
            width: 90%;
            max-width: 500px;
            max-height: 90vh;
            overflow-y: auto;
            padding: 2rem;
            position: relative;
        }
        
        .close-modal {
            position: absolute;
            top: 15px;
            right: 15px;
            font-size: 1.5rem;
            cursor: pointer;
        }
        
        .modal-title {
            margin-bottom: 1.5rem;
            color: var(--primary-color);
        }
        
        .form-group {
            margin-bottom: 1rem;
        }
        
        .form-group label {
            display: block;
            margin-bottom: 0.5rem;
            font-weight: bold;
        }
        
        .form-group input, .form-group textarea, .form-group select {
            width: 100%;
            padding: 0.5rem;
            border: 1px solid #ddd;
            border-radius: 5px;
        }
        
        .form-actions {
            display: flex;
            justify-content: flex-end;
            gap: 1rem;
            margin-top: 1.5rem;
        }
        
        .btn {
            padding: 0.5rem 1rem;
            border-radius: 5px;
            cursor: pointer;
            border: none;
        }
        
        .btn-primary {
            background-color: var(--primary-color);
            color: white;
        }
        
        .btn-secondary {
            background-color: #ddd;
        }
        
        /* Image Upload */
        .image-upload {
            border: 2px dashed #ddd;
            border-radius: 5px;
            padding: 1rem;
            text-align: center;
            margin-bottom: 1rem;
            cursor: pointer;
        }
        
        .image-upload img {
            max-width: 100%;
            max-height: 200px;
            margin-bottom: 1rem;
        }
        
        /* Responsive */
        @media (max-width: 768px) {
            .menu-items {
                grid-template-columns: repeat(auto-fill, minmax(250px, 1fr));
            }
            
            .logo {
                font-size: 2rem;
            }
            
            .slogan {
                font-size: 1rem;
            }
        }
    </style>
</head>
<body>
    <!-- WhatsApp Button -->
    <a href="https://wa.me/5511999999999?text=Olá,%20gostaria%20de%20fazer%20um%20pedido!" class="whatsapp-btn">
        <i class="fab fa-whatsapp"></i>
    </a>
    
    <!-- Header with Banner -->
    <header>
        <div class="banner-content">
            <div class="logo">Hamburgueria Delícia</div>
            <div class="slogan">Os melhores hambúrgueres da cidade!</div>
        </div>
    </header>
    
    <!-- Table QR/NFC Section -->
    <section class="table-section">
        <div class="container">
            <h3>Mesa #<span id="table-number">--</span></h3>
            <div class="table-info">
                <button class="qr-btn" id="scan-qr-btn">
                    <i class="fas fa-qrcode"></i> Ler QR Code
                </button>
                <span>ou</span>
                <button class="nfc-btn" id="scan-nfc-btn">
                    <i class="fas fa-wifi"></i> Aproxime do NFC
                </button>
            </div>
        </div>
    </section>
    
    <!-- Featured Section -->
    <section class="featured-section">
        <div class="container">
            <h2 class="featured-title">Destaque da Semana</h2>
            <p>Experimente nosso novo hambúrguer especial com bacon caramelizado e molho secreto!</p>
        </div>
    </section>
    
    <!-- Menu Categories -->
    <section class="container">
        <div class="menu-categories">
            <button class="category-btn active" data-category="all">Todos</button>
            <button class="category-btn" data-category="burgers">Hambúrgueres</button>
            <button class="category-btn" data-category="combos">Combos</button>
            <button class="category-btn" data-category="sides">Acompanhamentos</button>
            <button class="category-btn" data-category="drinks">Bebidas</button>
            <button class="category-btn" data-category="desserts">Sobremesas</button>
        </div>
    </section>
    
    <!-- Menu Items -->
    <section class="container">
        <div class="menu-items" id="menu-items-container">
            <!-- Item 1 -->
            <div class="menu-item" data-category="burgers">
                <img src="https://images.unsplash.com/photo-1568901346375-23c9450c58cd?ixlib=rb-1.2.1&auto=format&fit=crop&w=1350&q=80" alt="Hambúrguer Clássico" class="item-image">
                <div class="item-details">
                    <div class="item-header">
                        <span class="item-name">Clássico</span>
                        <span class="item-price">R$ 25,90</span>
                    </div>
                    <p class="item-description">Pão brioche, hambúrguer 180g, queijo, alface, tomate e molho especial.</p>
                    <div class="item-footer">
                        <button class="add-to-cart">
                            <i class="fas fa-plus"></i> Adicionar
                        </button>
                        <span class="highlight-badge">Mais vendido</span>
                    </div>
                </div>
            </div>
            
            <!-- Item 2 -->
            <div class="menu-item" data-category="burgers">
                <img src="https://images.unsplash.com/photo-1553979459-d2229ba7433b?ixlib=rb-1.2.1&auto=format&fit=crop&w=1350&q=80" alt="Hambúrguer Bacon" class="item-image">
                <div class="item-details">
                    <div class="item-header">
                        <span class="item-name">Bacon Crunch</span>
                        <span class="item-price">R$ 29,90</span>
                    </div>
                    <p class="item-description">Pão australiano, hambúrguer 200g, queijo cheddar, bacon crocante e molho barbecue.</p>
                    <div class="item-footer">
                        <button class="add-to-cart">
                            <i class="fas fa-plus"></i> Adicionar
                        </button>
                    </div>
                </div>
            </div>
            
            <!-- Item 3 -->
            <div class="menu-item" data-category="combos">
                <img src="https://images.unsplash.com/photo-1547584370-2cc98b8b8dc8?ixlib=rb-1.2.1&auto=format&fit=crop&w=1350&q=80" alt="Combo Familiar" class="item-image">
                <div class="item-details">
                    <div class="item-header">
                        <span class="item-name">Combo Familiar</span>
                        <span class="item-price">R$ 89,90</span>
                    </div>
                    <p class="item-description">4 hambúrgueres, 4 porções de batata, 4 refrigerantes e 1 sobremesa grande.</p>
                    <div class="item-footer">
                        <button class="add-to-cart">
                            <i class="fas fa-plus"></i> Adicionar
                        </button>
                        <span class="highlight-badge">Promoção</span>
                    </div>
                </div>
            </div>
            
            <!-- Item 4 -->
            <div class="menu-item" data-category="sides">
                <img src="https://images.unsplash.com/photo-1541592106381-b31e9677c0e5?ixlib=rb-1.2.1&auto=format&fit=crop&w=1350&q=80" alt="Batata Frita" class="item-image">
                <div class="item-details">
                    <div class="item-header">
                        <span class="item-name">Batata Frita</span>
                        <span class="item-price">R$ 12,90</span>
                    </div>
                    <p class="item-description">Porção de batata frita crocante com opção de molhos.</p>
                    <div class="item-footer">
                        <button class="add-to-cart">
                            <i class="fas fa-plus"></i> Adicionar
                        </button>
                    </div>
                </div>
            </div>
            
            <!-- Item 5 -->
            <div class="menu-item" data-category="drinks">
                <img src="https://images.unsplash.com/photo-1551029506-0807df4e2031?ixlib=rb-1.2.1&auto=format&fit=crop&w=1350&q=80" alt="Refrigerante" class="item-image">
                <div class="item-details">
                    <div class="item-header">
                        <span class="item-name">Refrigerante</span>
                        <span class="item-price">R$ 7,90</span>
                    </div>
                    <p class="item-description">Lata 350ml - Coca-Cola, Guaraná, Fanta ou Sprite.</p>
                    <div class="item-footer">
                        <button class="add-to-cart">
                            <i class="fas fa-plus"></i> Adicionar
                        </button>
                    </div>
                </div>
            </div>
            
            <!-- Item 6 -->
            <div class="menu-item" data-category="desserts">
                <img src="https://images.unsplash.com/photo-1563805042-7684c019e1cb?ixlib=rb-1.2.1&auto=format&fit=crop&w=1350&q=80" alt="Milkshake" class="item-image">
                <div class="item-details">
                    <div class="item-header">
                        <span class="item-name">Milkshake</span>
                        <span class="item-price">R$ 15,90</span>
                    </div>
                    <p class="item-description">Copo 500ml - Chocolate, Morango, Ovomaltine ou Doce de Leite.</p>
                    <div class="item-footer">
                        <button class="add-to-cart">
                            <i class="fas fa-plus"></i> Adicionar
                        </button>
                        <span class="highlight-badge">Novidade</span>
                    </div>
                </div>
            </div>
        </div>
    </section>
    
    <!-- Footer -->
    <footer>
        <div class="container">
            <div class="contact-info">
                <p><i class="fas fa-map-marker-alt"></i> Rua dos Sabores, 123 - Centro</p>
                <p><i class="fas fa-phone"></i> (11) 9999-9999</p>
                <p><i class="fas fa-clock"></i> Ter-Dom: 18h-23h</p>
            </div>
            <div class="social-links">
                <a href="#" class="social-link"><i class="fab fa-facebook"></i></a>
                <a href="#" class="social-link"><i class="fab fa-instagram"></i></a>
                <a href="#" class="social-link"><i class="fab fa-twitter"></i></a>
            </div>
            <p class="copyright">© 2023 Hamburgueria Delícia. Todos os direitos reservados.</p>
        </div>
    </footer>
    
    <!-- Admin Panel -->
    <div class="admin-panel">
        <div class="admin-btn" id="admin-btn">
            <i class="fas fa-cog"></i>
        </div>
        <div class="admin-options" id="admin-options">
            <div class="admin-option" id="edit-menu-item">
                <i class="fas fa-edit"></i> Editar Item
            </div>
            <div class="admin-option" id="add-menu-item">
                <i class="fas fa-plus"></i> Adicionar Item
            </div>
            <div class="admin-option" id="edit-banner">
                <i class="fas fa-image"></i> Alterar Banner
            </div>
            <div class="admin-option" id="edit-featured">
                <i class="fas fa-star"></i> Editar Destaque
            </div>
        </div>
    </div>
    
    <!-- QR Code Modal -->
    <div class="modal" id="qr-modal">
        <div class="modal-content">
            <span class="close-modal" id="close-qr-modal">&times;</span>
            <h2 class="modal-title">Ler QR Code da Mesa</h2>
            <div id="qr-reader" style="width: 100%; margin: 1rem 0;"></div>
            <p style="text-align: center;">Aponte a câmera para o QR code na mesa</p>
        </div>
    </div>
    
    <!-- Edit Item Modal -->
    <div class="modal" id="edit-item-modal">
        <div class="modal-content">
            <span class="close-modal" id="close-edit-modal">&times;</span>
            <h2 class="modal-title">Editar Item do Cardápio</h2>
            <div class="form-group">
                <label for="edit-item-name">Nome do Item</label>
                <input type="text" id="edit-item-name" placeholder="Ex: Hambúrguer Clássico">
            </div>
            <div class="form-group">
                <label for="edit-item-price">Preço</label>
                <input type="text" id="edit-item-price" placeholder="Ex: 25,90">
            </div>
            <div class="form-group">
                <label for="edit-item-description">Descrição</label>
                <textarea id="edit-item-description" rows="3" placeholder="Descreva o item"></textarea>
            </div>
            <div class="form-group">
                <label for="edit-item-category">Categoria</label>
                <select id="edit-item-category">
                    <option value="burgers">Hambúrgueres</option>
                    <option value="combos">Combos</option>
                    <option value="sides">Acompanhamentos</option>
                    <option value="drinks">Bebidas</option>
                    <option value="desserts">Sobremesas</option>
                </select>
            </div>
            <div class="form-group">
                <label>Imagem do Item</label>
                <div class="image-upload" id="edit-item-image-upload">
                    <img id="edit-item-image-preview" src="https://via.placeholder.com/300x200?text=Clique+para+alterar" alt="Preview">
                    <p>Clique para alterar a imagem</p>
                    <input type="file" id="edit-item-image-input" accept="image/*" style="display: none;">
                </div>
            </div>
            <div class="form-group">
                <label>
                    <input type="checkbox" id="edit-item-highlight"> Destacar este item
                </label>
            </div>
            <div class="form-actions">
                <button class="btn btn-secondary" id="cancel-edit-item">Cancelar</button>
                <button class="btn btn-primary" id="save-edit-item">Salvar</button>
            </div>
        </div>
    </div>
    
    <!-- Add Item Modal -->
    <div class="modal" id="add-item-modal">
        <div class="modal-content">
            <span class="close-modal" id="close-add-modal">&times;</span>
            <h2 class="modal-title">Adicionar Novo Item</h2>
            <div class="form-group">
                <label for="add-item-name">Nome do Item</label>
                <input type="text" id="add-item-name" placeholder="Ex: Hambúrguer Especial">
            </div>
            <div class="form-group">
                <label for="add-item-price">Preço</label>
                <input type="text" id="add-item-price" placeholder="Ex: 29,90">
            </div>
            <div class="form-group">
                <label for="add-item-description">Descrição</label>
                <textarea id="add-item-description" rows="3" placeholder="Descreva o item"></textarea>
            </div>
            <div class="form-group">
                <label for="add-item-category">Categoria</label>
                <select id="add-item-category">
                    <option value="burgers">Hambúrgueres</option>
                    <option value="combos">Combos</option>
                    <option value="sides">Acompanhamentos</option>
                    <option value="drinks">Bebidas</option>
                    <option value="desserts">Sobremesas</option>
                </select>
            </div>
            <div class="form-group">
                <label>Imagem do Item</label>
                <div class="image-upload" id="add-item-image-upload">
                    <img id="add-item-image-preview" src="https://via.placeholder.com/300x200?text=Clique+para+adicionar" alt="Preview">
                    <p>Clique para adicionar uma imagem</p>
                    <input type="file" id="add-item-image-input" accept="image/*" style="display: none;">
                </div>
            </div>
            <div class="form-group">
                <label>
                    <input type="checkbox" id="add-item-highlight"> Destacar este item
                </label>
            </div>
            <div class="form-actions">
                <button class="btn btn-secondary" id="cancel-add-item">Cancelar</button>
                <button class="btn btn-primary" id="save-add-item">Adicionar</button>
            </div>
        </div>
    </div>
    
    <!-- Edit Banner Modal -->
    <div class="modal" id="edit-banner-modal">
        <div class="modal-content">
            <span class="close-modal" id="close-banner-modal">&times;</span>
            <h2 class="modal-title">Alterar Banner</h2>
            <div class="form-group">
                <label for="banner-title">Título</label>
                <input type="text" id="banner-title" placeholder="Nome da Hamburgueria">
            </div>
            <div class="form-group">
                <label for="banner-slogan">Slogan</label>
                <input type="text" id="banner-slogan" placeholder="Slogan ou frase de efeito">
            </div>
            <div class="form-group">
                <label>Imagem de Fundo</label>
                <div class="image-upload" id="banner-image-upload">
                    <img id="banner-image-preview" src="https://images.unsplash.com/photo-1586190848861-99aa4a171e90?ixlib=rb-1.2.1&auto=format&fit=crop&w=1350&q=80" alt="Preview">
                    <p>Clique para alterar a imagem</p>
                    <input type="file" id="banner-image-input" accept="image/*" style="display: none;">
                </div>
            </div>
            <div class="form-actions">
                <button class="btn btn-secondary" id="cancel-banner-edit">Cancelar</button>
                <button class="btn btn-primary" id="save-banner-edit">Salvar</button>
            </div>
        </div>
    </div>
    
    <!-- Edit Featured Modal -->
    <div class="modal" id="edit-featured-modal">
        <div class="modal-content">
            <span class="close-modal" id="close-featured-modal">&times;</span>
            <h2 class="modal-title">Editar Destaque</h2>
            <div class="form-group">
                <label for="featured-title">Título</label>
                <input type="text" id="featured-title" placeholder="Título do destaque">
            </div>
            <div class="form-group">
                <label for="featured-description">Descrição</label>
                <textarea id="featured-description" rows="3" placeholder="Descrição do destaque"></textarea>
            </div>
            <div class="form-actions">
                <button class="btn btn-secondary" id="cancel-featured-edit">Cancelar</button>
                <button class="btn btn-primary" id="save-featured-edit">Salvar</button>
            </div>
        </div>
    </div>
    
    <script src="https://cdn.jsdelivr.net/npm/jsqr@1.4.0/dist/jsQR.min.js"></script>
    <script>
        // Admin Panel Toggle
        document.getElementById('admin-btn').addEventListener('click', function() {
            document.getElementById('admin-options').classList.toggle('show');
        });
        
        // Close admin options when clicking outside
        document.addEventListener('click', function(e) {
            if (!e.target.closest('.admin-panel')) {
                document.getElementById('admin-options').classList.remove('show');
            }
        });
        
        // Menu Category Filter
        const categoryBtns = document.querySelectorAll('.category-btn');
        const menuItems = document.querySelectorAll('.menu-item');
        
        categoryBtns.forEach(btn => {
            btn.addEventListener('click', function() {
                // Remove active class from all buttons
                categoryBtns.forEach(b => b.classList.remove('active'));
                // Add active class to clicked button
                this.classList.add('active');
                
                const category = this.getAttribute('data-category');
                
                menuItems.forEach(item => {
                    if (category === 'all' || item.getAttribute('data-category') === category) {
                        item.style.display = 'block';
                    } else {
                        item.style.display = 'none';
                    }
                });
            });
        });
        
        // QR Code Scanner
        const qrModal = document.getElementById('qr-modal');
        const scanQrBtn = document.getElementById('scan-qr-btn');
        const closeQrModal = document.getElementById('close-qr-modal');
        
        scanQrBtn.addEventListener('click', function() {
            qrModal.classList.add('show');
            startQRScanner();
        });
        
        closeQrModal.addEventListener('click', function() {
            qrModal.classList.remove('show');
            stopQRScanner();
        });
        
        function startQRScanner() {
            const qrReader = document.getElementById('qr-reader');
            qrReader.innerHTML = '<canvas id="qr-canvas" style="width: 100%;"></canvas>';
            
            const canvas = document.getElementById('qr-canvas');
            const context = canvas.getContext('2d');
            
            // Set canvas size
            canvas.width = qrReader.offsetWidth;
            canvas.height = qrReader.offsetHeight;
            
            // Access camera
            navigator.mediaDevices.getUserMedia({ video: { facingMode: "environment" } })
                .then(function(stream) {
                    const video = document.createElement('video');
                    video.srcObject = stream;
                    video.setAttribute('playsinline', 'true');
                    video.play();
                    
                    function tick() {
                        if (video.readyState === video.HAVE_ENOUGH_DATA) {
                            canvas.height = video.videoHeight;
                            canvas.width = video.videoWidth;
                            context.drawImage(video, 0, 0, canvas.width, canvas.height);
                            
                            const imageData = context.getImageData(0, 0, canvas.width, canvas.height);
                            const code = jsQR(imageData.data, imageData.width, imageData.height, {
                                inversionAttempts: "dontInvert",
                            });
                            
                            if (code) {
                                document.getElementById('table-number').textContent = code.data;
                                qrModal.classList.remove('show');
                                stopQRScanner();
                            }
                        }
                        requestAnimationFrame(tick);
                    }
                    
                    tick();
                })
                .catch(function(err) {
                    console.error("Error accessing camera: ", err);
                    alert("Não foi possível acessar a câmera. Por favor, verifique as permissões.");
                });
        }
        
        function stopQRScanner() {
            const video = document.querySelector('video');
            if (video && video.srcObject) {
                video.srcObject.getTracks().forEach(track => track.stop());
            }
        }
        
        // NFC Scanner (simulated)
        document.getElementById('scan-nfc-btn').addEventListener('click', function() {
            alert("Aproxime seu dispositivo do tag NFC na mesa...");
            // Simulate NFC detection after 2 seconds
            setTimeout(function() {
                document.getElementById('table-number').textContent = "15";
            }, 2000);
        });
        
        // Edit Item Modal
        const editItemModal = document.getElementById('edit-item-modal');
        const editItemBtn = document.getElementById('edit-menu-item');
        const closeEditModal = document.getElementById('close-edit-modal');
        const cancelEditItem = document.getElementById('cancel-edit-item');
        
        editItemBtn.addEventListener('click', function() {
            // In a real app, you would get the item data to edit
            editItemModal.classList.add('show');
        });
        
        closeEditModal.addEventListener('click', function() {
            editItemModal.classList.remove('show');
        });
        
        cancelEditItem.addEventListener('click', function() {
            editItemModal.classList.remove('show');
        });
        
        // Image Upload for Edit Item
        document.getElementById('edit-item-image-upload').addEventListener('click', function() {
            document.getElementById('edit-item-image-input').click();
        });
        
        document.getElementById('edit-item-image-input').addEventListener('change', function(e) {
            if (e.target.files.length > 0) {
                const reader = new FileReader();
                reader.onload = function(event) {
                    document.getElementById('edit-item-image-preview').src = event.target.result;
                };
                reader.readAsDataURL(e.target.files[0]);
            }
        });
        
        // Save Edit Item
        document.getElementById('save-edit-item').addEventListener('click', function() {
            // In a real app, you would save the changes to your database
            alert("Item salvo com sucesso!");
            editItemModal.classList.remove('show');
        });
        
        // Add Item Modal
        const addItemModal = document.getElementById('add-item-modal');
        const addItemBtn = document.getElementById('add-menu-item');
        const closeAddModal = document.getElementById('close-add-modal');
        const cancelAddItem = document.getElementById('cancel-add-item');
        
        addItemBtn.addEventListener('click', function() {
            addItemModal.classList.add('show');
        });
        
        closeAddModal.addEventListener('click', function() {
            addItemModal.classList.remove('show');
        });
        
        cancelAddItem.addEventListener('click', function() {
            addItemModal.classList.remove('show');
        });
        
        // Image Upload for Add Item
        document.getElementById('add-item-image-upload').addEventListener('click', function() {
            document.getElementById('add-item-image-input').click();
        });
        
        document.getElementById('add-item-image-input').addEventListener('change', function(e) {
            if (e.target.files.length > 0) {
                const reader = new FileReader();
                reader.onload = function(event) {
                    document.getElementById('add-item-image-preview').src = event.target.result;
                };
                reader.readAsDataURL(e.target.files[0]);
            }
        });
        
        // Save Add Item
        document.getElementById('save-add-item').addEventListener('click', function() {
            // In a real app, you would add the new item to your database
            alert("Item adicionado com sucesso!");
            addItemModal.classList.remove('show');
        });
        
        // Edit Banner Modal
        const editBannerModal = document.getElementById('edit-banner-modal');
        const editBannerBtn = document.getElementById('edit-banner');
        const closeBannerModal = document.getElementById('close-banner-modal');
        const cancelBannerEdit = document.getElementById('cancel-banner-edit');
        
        editBannerBtn.addEventListener('click', function() {
            // Set current values
            document.getElementById('banner-title').value = document.querySelector('.logo').textContent;
            document.getElementById('banner-slogan').value = document.querySelector('.slogan').textContent;
            editBannerModal.classList.add('show');
        });
        
        closeBannerModal.addEventListener('click', function() {
            editBannerModal.classList.remove('show');
        });
        
        cancelBannerEdit.addEventListener('click', function() {
            editBannerModal.classList.remove('show');
        });
        
        // Image Upload for Banner
        document.getElementById('banner-image-upload').addEventListener('click', function() {
            document.getElementById('banner-image-input').click();
        });
        
        document.getElementById('banner-image-input').addEventListener('change', function(e) {
            if (e.target.files.length > 0) {
                const reader = new FileReader();
                reader.onload = function(event) {
                    document.getElementById('banner-image-preview').src = event.target.result;
                };
                reader.readAsDataURL(e.target.files[0]);
            }
        });
        
        // Save Banner Edit
        document.getElementById('save-banner-edit').addEventListener('click', function() {
            const newTitle = document.getElementById('banner-title').value;
            const newSlogan = document.getElementById('banner-slogan').value;
            
            document.querySelector('.logo').textContent = newTitle;
            document.querySelector('.slogan').textContent = newSlogan;
            
            // In a real app, you would also update the background image
            editBannerModal.classList.remove('show');
            alert("Banner atualizado com sucesso!");
        });
        
        // Edit Featured Modal
        const editFeaturedModal = document.getElementById('edit-featured-modal');
        const editFeaturedBtn = document.getElementById('edit-featured');
        const closeFeaturedModal = document.getElementById('close-featured-modal');
        const cancelFeaturedEdit = document.getElementById('cancel-featured-edit');
        
        editFeaturedBtn.addEventListener('click', function() {
            // Set current values
            document.getElementById('featured-title').value = document.querySelector('.featured-title').textContent;
            document.getElementById('featured-description').value = document.querySelector('.featured-section p').textContent;
            editFeaturedModal.classList.add('show');
        });
        
        closeFeaturedModal.addEventListener('click', function() {
            editFeaturedModal.classList.remove('show');
        });
        
        cancelFeaturedEdit.addEventListener('click', function() {
            editFeaturedModal.classList.remove('show');
        });
        
        // Save Featured Edit
        document.getElementById('save-featured-edit').addEventListener('click', function() {
            const newTitle = document.getElementById('featured-title').value;
            const newDescription = document.getElementById('featured-description').value;
            
            document.querySelector('.featured-title').textContent = newTitle;
            document.querySelector('.featured-section p').textContent = newDescription;
            
            editFeaturedModal.classList.remove('show');
            alert("Destaque atualizado com sucesso!");
        });
        
        // Add to Cart functionality
        const addToCartBtns = document.querySelectorAll('.add-to-cart');
        
        addToCartBtns.forEach(btn => {
            btn.addEventListener('click', function() {
                const itemName = this.closest('.menu-item').querySelector('.item-name').textContent;
                alert(`${itemName} adicionado ao carrinho!`);
            });
        });
    </script>
</body>
</html>
