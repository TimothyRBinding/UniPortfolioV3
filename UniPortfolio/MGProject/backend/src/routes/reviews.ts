import * as express from 'express'
import reviewController from '../controllers/reviewController'
const router = express.Router()

router.get('/', reviewController.getAllReviews)
router.post('/', reviewController.saveReview)

export default router
